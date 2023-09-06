## Problem: reverse the number

ans = ans * 10 + lastDigit;

## Problem: base 10 compliment the number
### Bruteforce Approach
  - do convert number in to binary string
  - do apply compliment on number
  - convert complimented string to decimal again
### Efficient Approach
  - do n = ~n will give you answer with extra one's in left of the bits of anser
      - 5 = (0000-----101) and ~5 = (111------111010) we want last three bits only
  - we can do & with mask (00------00111) with ~n to get only needfull bits
  - To create a mask use loop
      - while (n != 0)
          - mast = (mask << 1) | 1; (to add set bit to the right)
          - n >> 1;
  - then ans = (~n & mask)

## Points for bits:
  - To find the last bit of any number do (number & 1)
  - And to get the next bit you should first right-shift the number (number >> 1)
  - Right shift or left shift is always padded with 0's
  - if last bit on the right is 1 then the number is odd otherwise it's event
  - if we find only 1 set bit (1) then the number is perfect square
