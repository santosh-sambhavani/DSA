
### Problem Recap:
- You have **n candies**.
- You want to distribute them among **3 children**.
- Each child can get **at most `limit` candies**.
- Find the total number of ways to do this.

---

- So any child can have at max `limit` candies. and considering `(totalCandies > limit)` is possible
  - Any child can have candies in the range of `0 -> min(totalCandies, limit)`
- So we will iterate over the range of `0 -> min(totalCandies, limit)` for first child's possble candies
- than we can calculate the max number of possible candies for second & third child & than we can get total count from that.
- this is how we can find max count for 2nd & 3rd child

<img width="638" alt="Screenshot 2025-06-01 at 4 21 34 PM" src="https://github.com/user-attachments/assets/ca829247-2cd2-4fbd-a2d0-d8b4b2602eba" />

- for more understanding checkout [code](https://github.com/santosh-sambhavani/DSA/blob/main/leetcode-daily/distribute-candies.ts)
