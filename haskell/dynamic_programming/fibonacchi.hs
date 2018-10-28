slowFibonacchi :: Int -> Int
slowFibonacchi n 
  | n == 0 = 0
  | n == 1 = 1
  | n >= 1 = slowFibonacchi (n-1) + slowFibonacchi (n-2)

fastFibonacchi = (0::Integer):1: zipWith (+) fastFibonacchi (tail fastFibonacchi)

fibonacchi :: Int -> Integer
fibonacchi n
  | n >= 0 = fastFibonacchi !! (n+1)