**Understanding the Image: Checking for Prime Numbers**

**What's the goal?**
* To figure out if a number (let's call it 'n') is a prime number or not.

**What's a prime number?**
* A prime number is a number that can only be divided evenly by 1 and itself. 

**How do we check?**
1. **Trial Division:** We try dividing 'n' by numbers starting from 2 up to a certain point.
2. **The Trick:** We only need to check up to the square root of 'n'. Why? Because divisors of a number come in pairs.

**Why Square Root of n?**
* Look at the example of 36. Its divisors are paired: (1, 36), (2, 18), (3, 12), (4, 9), (6, 6), (9, 4), (12, 3), (18, 2), (36, 1).
* Notice how in each pair, one number is less than or equal to the square root of 36 (which is 6), and the other is greater than or equal to 6.
* So, if we find a divisor less than or equal to the square root, we automatically know there's a corresponding divisor greater than the square root.

<img width="994" alt="Screenshot 2024-07-28 at 3 57 00 PM" src="https://github.com/user-attachments/assets/fe11ed6f-1a7b-4f87-a0ae-8d140e86486e">

**Conclusion:**
* If we check all numbers from 2 up to the square root of 'n' and none of them divide 'n' evenly, then 'n' is a prime number.

**In short:** We only need to check for divisors up to the square root of a number to determine if it's prime. This saves us time compared to checking up to the number itself.

<img width="994" alt="Screenshot 2024-07-28 at 3 57 16 PM" src="https://github.com/user-attachments/assets/bbd526b6-6ffa-4f1d-87ea-142dff612415">
