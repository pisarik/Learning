-- very slow, actually it is fibonacchi sequnce
-- but cool it is working :D
countSequenciesWithoutOneOne :: Int -> Int
countSequenciesWithoutOneOne n
  | n == 0 = 1
  | n == 1 = 2
  | n >= 1 = zeroEndCount (n-1) * 2 + oneEndCount (n-1)
  where zeroEndCount n
          | n == 1 = 1
          | n >= 1 = countSequenciesWithoutOneOne (n-1)
        oneEndCount n
          | n == 1 = 1
          | n >= 1 = zeroEndCount (n-1)