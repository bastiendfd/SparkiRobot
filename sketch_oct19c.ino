#include <sparki.h>

// SAFETY CONTRACT: this default lesson is deliberately LED-only.
// SAFE_IDLE_LED_ONLY: no motor or movement API is called by this sketch.
// It is safe to upload only after following README.md's hardware checklist.

const unsigned long STEP_DELAY_MS = 500;

void showColor(int red, int green, int blue) {
  sparki.RGB(red, green, blue);
  delay(STEP_DELAY_MS);
}

void setup() {
  // Make the safe idle state explicit before the repeating LED lesson begins.
  sparki.RGB(RGB_OFF);
}

void loop() {
  // A visible, stationary RGB exercise for learning the Sparki LED API.
  showColor(100, 0, 0);
  showColor(0, 100, 0);
  showColor(0, 0, 100);
  sparki.RGB(RGB_WHITE);
  delay(STEP_DELAY_MS);
  sparki.RGB(RGB_OFF);
  delay(STEP_DELAY_MS);
}
