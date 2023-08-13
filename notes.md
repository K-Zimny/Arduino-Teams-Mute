# Code walkthrough

## Debounce and button reading

### First run through

---

1. Button is Pressed.

---

2. Read our button pin.

   - Assign to `buttonReading`, value stored as 0.
     - 0 (LOW) is pressed.
     - 1 (HIGH) is NOT pressed.

---

3. Test to see if our button was pressed (true) and record that time.

   ***

   - Define var and states

     - `buttonReading`
       - when button is pressed pressed, `buttonReading` = 0;
     - `previousButtonState`
       - Init as 1 (`true`);
       - When our button is pressed the new state of that button is become 0 (Low).
       - It follows that the state, before our presses, would therefore be 1 (High).
     - `previousMillisTime`
       - On first run there is no previous Millis value, init as 0.

     ***

   - Walkthrough

     - If our `buttonReading` (0) is not equal to `previousButtonState` (1) // true;
     - Assign `previousMillisTime` (0) to the current `millis()`.
     - EX: 1000 for this walkthrough.

     ***

   - Explaniation

     - On press our current button state (0) is not equal to the previous button state (1). The if statement will run.
       - We're testing if the button has been pressed.
     - Set our `previousMillisTime` to the current runtime.
       - Its a bit confusing since the `previousMillisTime` is actually equal to the current millis time. This makes more sense after this code block, since we will again call `millis()` and then we can then compare that to the 'previous' Millis() time value we took.
       - We need to think of previous here as previous to the second call of millis() in the next if statement. That is the current millis() at the if statement call and the millis() value we took before that would then be considered the 'previous' value we took. Its a bit of a reference shift.
       - `previousMillisTIme` is previous to the next millis call().

     ***

   - Why

     - We need to take note of when that button was pressed. This will allow us to use it as a reference to make sure enough time has passed, so as to have the value of the button settle before we ensure our button has been pressed.
       - We need this debounce due to electrial signal fluxuations that occur when the button is pressed.
       - Without this we may pick up false positives resulting in undesired code execution.

---

4. Test if we have debounced the button press (true).

   - Define vars and states

     - `millis()`
       - Time in milliseconds since our program began.
     - `previousMillisTime`
       - The time stamp of when our button was pressed. EX: 1000 for this walkthrough.
         - Taken in the previous if statement.
     - `debouceDelay`
       - init as constant of 50.
       - This is the amount of time we will let pass (debounce) before we run our next conditional to prevent reading false positives on our button input.

     ***

   - Walkthrough

     - If `millis()` (the current time, Ex: 1100) minus `previousMillisTime` (ex: 1000), is greater than `debounceDelay` (50). Ex: 1100 - 1000 = 100. 100 > 50 // true
       - Run through our next code block.
     - If `millis()` (the current time, Ex: 1010) minus `previousMillisTime` (ex: 1000), is greater than `debounceDelay` (50). Ex: 1010 - 1000 = 10. 10 > 50 // false
       - The next code block is NOT executed.

   - Explaniation

     - If the current time minus our previous time reading is greater than our debounce delay time we can ensure that enough time has passed for us to have properly debounced the button.
     - If it is less than our debounce delay time, we dont want to run our code since the electrial fluxations have NOT settle and may result in false positives.

   - Why

     - We want to ensure that we dont pick up any false positives when our button is pressed. With this code we can ensure that one button press will only be counted as one.

---

5. Test if the button reading not equal to our button state (1).

   - Define vars and states

     - `buttonReading`
       - The value read on our button
     - `buttonState`
       - The init value of 1. The button starts the program as NOT pressed.

   - Walkthrough

     - If our button reading is not equal to our button state (1) run the next code block

   - Explaniation

     - This if statement will only run after our debounce time. The previous millis time stamp is finally set the loop before the button is released. Its only when the button is released that we can allow the debounce statement to execute. When that starts to run it must mean that we have released the button. Therefor this current if statement will test with `buttonReading` = 0.
     -
