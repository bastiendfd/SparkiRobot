# SparkiRobot — safe LED-only starter

A small Arduino/Sparki learning sketch that demonstrates the RGB LED **without driving the robot**. The repository's default program contains no motor commands and performs **no autonomous movement** after boot or at any later time.

> **Status:** source and static safety checks only. This repository has **no hardware verification** and makes no claim that a particular board, battery, library release, upload tool, or physical robot has been tested.

## What the sketch does

`sketch_oct19c.ino` turns the Sparki RGB LED red, green, blue, white, and off in a repeating sequence. It calls no `sparki.move...` or motor API. The LED sequence starts after boot; wheel motion does not.

## Hardware safety checklist

Before connecting USB, switching on the robot, or uploading any sketch:

1. Put the robot on a stable, clear bench with its **wheels elevated** (or remove wheel contact) for first power-up and every code change.
2. Keep people, pets, hands, loose clothing, cables, liquids, stairs, edges, and obstacles away from the work area. Do not run a mobile robot near people or where it could fall.
3. Keep a clear path to the power switch and USB cable. If behavior is unexpected, use the board/robot power switch to **power off**, then disconnect USB or battery power before inspecting it.
4. Do not leave a powered robot unattended. Stop work immediately if the robot is hot, damaged, swollen, leaking, smells unusual, or behaves erratically.
5. Use only the battery type, charger, polarity, and charging procedure specified by the robot and battery manufacturers. Charge on a suitable non-flammable surface and do not charge damaged batteries.

The LED-only sketch is intentionally stationary, but this checklist remains necessary: an incorrect upload, wiring issue, previous firmware, or an unexpected hardware fault can still create risk.

## Software setup and upload

1. Install the Arduino IDE or Arduino CLI from its official documentation.
2. Install the Sparki library that provides `sparki.h` using the library's upstream installation instructions. This repository does not bundle that library.
3. Select the board and serial port specified by your Sparki/Arduino documentation.
4. Open `sketch_oct19c.ino`, compile, and upload while the wheels remain elevated.
5. Confirm that only the LED changes. If any wheel moves, immediately power off and investigate before proceeding.

### Version guidance

Hardware variants and Arduino/Sparki library compatibility differ. Use a currently supported Arduino IDE/CLI and the board package and Sparki library release recommended by the manufacturer for **your exact hardware**. Record the versions you use in an issue or lab note. No version combination is asserted as compatible here because it has not been hardware verified.

## Adding motion safely

This starter deliberately provides no motion-enabled mode. Do not add a movement call merely to make the demo more exciting. If you create a separate experiment:

- start with wheels elevated and a clear, supervised area;
- add one small, time-bounded command at a time;
- ensure a tested stop/power-off procedure is immediately available;
- keep a physical observer beside the power switch;
- test away from people, pets, edges, stairs, obstacles, and fragile items; and
- keep the safe LED-only sketch unchanged as the recovery baseline.

Do not assume a software stop command is a safety system. Physical power-off is the fallback when behavior is unexpected.

## Local checks

Run the repository's static safety contract:

```bash
python -m unittest discover -s tests -v
```

The check confirms that the default sketch has the safe-idle marker, has no common Sparki motor/movement calls, and that this README retains key safety and verification statements. It does **not** compile against a hardware library, upload firmware, move a robot, or replace bench testing.

GitHub Actions runs the same static checks plus whitespace and simple secret-pattern scans. CI is intentionally not presented as hardware verification.

## Repository layout

- `sketch_oct19c.ino` — LED-only Arduino/Sparki lesson
- `tests/test_safety_contract.py` — offline static safety checks
- `.github/workflows/ci.yml` — static CI; no hardware access
- `SECURITY.md` — responsible reporting guidance
