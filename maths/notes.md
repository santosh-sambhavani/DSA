### Problem: Seive algorithem to find all prime numbers less than n
- Traverse till root n & eleminate the multiple of prime numbers 
- why till root n ref: https://youtu.be/7VPA-HjjUmU?si=91VLk_do-qbx601Y
- Refer code for more

### Problem: Segmented seive algorithm
- Segmented seive was introduced to reduce the problem of space complexity in seive algorithem
- Here we first find the prime numbers till square root of n
- than eleminate the multiples of it in every range of square root of n till n
- why only primes & why till root n 
  - any number have the factors of multiple only till root n 
        after that the factors repeat with alternative positions that's why only till root n 
        and root n of n will be sufficient to 
        find for all numbers less than n that the number less than n is prime or not
  - why we have choosen only primes because the numbers that are multiple of 
        non prime number will be also multiple of prime number till root number
        so no need to consider non prime numbers to find multiples

### Concept: Modular exponential
- We should convert the larger numbers in to the range till 10^9 by (n % (10^9 + 7))
- Fast exponential: refer to code 
  ![Screenshot from 2023-09-26 20-46-56](https://github.com/Santosh-745/DSA/assets/80413971/0fe57eba-f72f-459c-a585-cdf54f402c2f)
