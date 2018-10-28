mergesort :: (Ord a) => [a] -> [a]
mergesort [] = []
mergesort [a] = [a]
mergesort xs = merge (mergesort leftPart) (mergesort rightPart)
  where merge :: (Ord a) => [a] -> [a] -> [a]
        merge [] ys = ys
        merge xs [] = xs
        merge (x:xs) (y:ys) 
          | x < y = x:merge xs (y:ys)
          | otherwise = y:merge (x:xs) ys
        half = length xs `div` 2
        leftPart = take half xs
        rightPart = drop half xs

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) 
  | x < y = x:merge xs (y:ys)
  | otherwise = y:merge (x:xs) ys