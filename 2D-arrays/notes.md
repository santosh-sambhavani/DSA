### Pattern 1: Spiral traverse or 90 Deegree rotation
  - In this type of question need to perform action in clockwise or anti-clockwise
  - and remove row & column every time we process that row & column
  - For 90 degre other method is (rotate matrix from diagonal & than from vertical middle line) will rotate it 90 degre

### Pattern 2: Search in row wise & column wise sorted array
  - start from top right corner
  - if value is bigger than desired value than go to left in row
  - and if it's smalle than wanted value than move down in column

### Pattern 3: find median or find kth smallest element in row wise sorted matrix
  - The main idea is to check for every possible ans the count of smaller elements than the possible sol
  - if the count we get is less than move loew to mid else high to mid
