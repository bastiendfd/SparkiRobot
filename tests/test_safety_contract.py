#!/usr/bin/env python3
"""Static safety-contract checks for the educational Sparki sketch.

These tests deliberately do not connect to or control hardware.
"""
from pathlib import Path
import re
import unittest

ROOT = Path(__file__).resolve().parents[1]
SKETCH = ROOT / "sketch_oct19c.ino"
README = ROOT / "README.md"


class SafetyContractTests(unittest.TestCase):
    def setUp(self):
        self.source = SKETCH.read_text(encoding="utf-8")

    def test_default_sketch_has_no_motor_motion_calls(self):
        """The repository's default sketch must remain LED-only at runtime."""
        motion_calls = re.compile(
            r"\bsparki\s*\.\s*(?:moveForward|moveBackward|moveLeft|moveRight|"
            r"moveStop|move(?:\w*)|motor(?:\w*))\s*\(",
            re.IGNORECASE,
        )
        self.assertIsNone(motion_calls.search(self.source))

    def test_default_sketch_has_a_safe_idle_marker(self):
        self.assertIn("SAFE_IDLE_LED_ONLY", self.source)

    def test_readme_states_hardware_and_verification_limits(self):
        readme = README.read_text(encoding="utf-8").lower()
        for required_phrase in (
            "wheels elevated",
            "power off",
            "no hardware verification",
            "no autonomous movement",
        ):
            self.assertIn(required_phrase, readme)


if __name__ == "__main__":
    unittest.main()
