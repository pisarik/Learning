chain :: (Integral a) => a -> a -> [a]
chain _ 1 = [1]
chain mult n
  | even n = n:chain mult (n `div` 2)
  | odd n = n:chain mult (n * mult + 1)