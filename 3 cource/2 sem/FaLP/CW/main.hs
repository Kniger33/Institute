power_set [] = [[]]
power_set (h:t) = do
  array_tail ++ map (h:) array_tail
    where array_tail = power_set t

с [] 0 = []
c array n = do
  filter (\x -> length x == n) result
    where result = power_set array

main = do
  print $ power_set [1, 2, 3]
