module Units
( marine
) where

import Economy

data Unit = Unit { hitPoints :: Int 
                 , cost :: Cost
                 , supply :: Int
                 , groundAttack :: Int
                 , airAttack :: Int
                 , armor :: Int
                 } deriving (Show)


marine :: Unit
marine = Unit {hitPoints=45, cost = (50, 0),
               supply = 1, groundAttack = 6, airAttack = 6,
               armor = 0}