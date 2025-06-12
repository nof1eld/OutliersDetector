# Outliers Detection Program

This program reads a list of votes (numbers), sorts them, and detects outliers using the Interquartile Range (IQR) method.

## How it works
- The user is prompted to enter the data set (e.g. votes)
- The votes are sorted in ascending order.
- The program calculates the first quartile (Q1) and third quartile (Q3).
- The IQR is calculated as Q3 - Q1.
- Outliers are defined as values less than Q1 - 1.5*IQR or greater than Q3 + 1.5*IQR.
- The program prints all votes and then lists any outliers found.

## Where it can be used
- To check for anomalous or extreme values in small datasets, such as survey results, scores, or measurements.
- In educational settings to demonstrate basic statistics and outlier detection.
- For quick manual data cleaning before further analysis.

## How to run
1. Compile the code:
   ```bash
   g++ -o outliers-detection main.cpp
   ```
2. Run the program:
   ```bash
   ./outliers-detection
   ```
3. Follow the prompts to enter the number of votes and each vote value.

## Notes
- The program uses bubble sort, which is simple but slow for large datasets.
- Only works with at least 4 votes.

## Usage Example
Suppose you want to check for outliers in Transfermarkt website, where a player's market-value is collected from votings of website's users. You can enter the votes as your dataset:

```
Enter the total number of votes: 7
Enter vote 1: 10.5
Enter vote 2: 12.0
Enter vote 3: 13.2
Enter vote 4: 14.0
Enter vote 5: 15.5
Enter vote 6: 16.0
Enter vote 7: 50.0
```

Output:
```
-----votes-----
Vote 1: 10.500000
Vote 2: 12.000000
Vote 3: 13.200000
Vote 4: 14.000000
Vote 5: 15.500000
Vote 6: 16.000000
Vote 7: 50.000000
-----outliers-----
Vote 7: 50.000000 is an outlier
```

This helps you spot extremely biased or hateful votes for a player's market-value.

You can then apply less weight to this votes or completely ignore them.