{-
Задача 1. Да се дефинира функцията isLeapYear year, която проверява дали годината year
е високосна.

ПримерИ:
    isLeapYear 1984 -> True
    isLeapYear 1995 -> False
    isLeapYear 2000 -> True
    isLeapYear 2100 -> False
-}
isDivisibleBy :: Integer -> Integer -> Bool
n `isDivisibleBy` k = n `mod` k == 0

-- Логичекски (булев) израз, съответстващ на дефиницията: една година е високосна, ако:
-- се дели на 4, но не и на 100, или ако се дели на 400.
isLeapYear :: Integer -> Bool
isLeapYear year = (year `isDivisibleBy` 4 && not (year `isDivisibleBy` 100))
            || (year `isDivisibleBy` 400)

{-
Задача 2. Напишете функция, която обръща цифрите на числото n.

Примери:
    reverseDigits 0     -> 0
    reverseDigits 5     -> 5
    reverseDigits 12345 -> 54321
    reverseDigits 1212  -> 2121
    reverseDigits 1000  -> 1
-}
reverseDigits :: Integer -> Integer
reverseDigits n = helper n 0 where
    helper i res =
        if i == 0
            then res
            else helper (i `div` 10) (10 * res + i `mod` 10)

{-
Задача 3. Прости числа: дефинирайте функцията isPrime n, която приема цялото число n
и проверява дали то е просто.

Примери:
    isPrime 1   -> False
    isPrime 2   -> True
    isPrime 3   -> True
    isPrime 52  -> False
    isPrime 71  -> True
-}
isPrime :: Integer -> Bool
isPrime n = n >= 2 && helper 2 where
    helper i
        | i > sqrtn         = True
        | n `mod` i == 0    = False
        | otherwise         = helper (i + 1) where
            sqrtn = floor (sqrt (fromIntegral n))

{-
Задача 4. Дефинирайте функцияга sumPrimes a b, която връща сумата на всички прости числа
в интервала от a до b.

Примери:
    sumPrimes 1 10  -> 17
    sumPrimes 2 5   -> 10
-}
sumPrimes :: Integer -> Integer -> Integer
sumPrimes a b
    | a > b     = 0
    | isPrime a = a + sumPrimes (a + 1) b
    | otherwise = sumPrimes (a + 1) b

{-
Задача 5. Да се дефинира функцията isPerfectNumber n, която приема целочисления аргумент n и
връща дали той е перфектно число. Перфектно число се нарича всяко чяло число, равно на сбора на
собствeните си делители.

Примери:
    isPerfectNumber 6    -> True
    isPerfectNumber 8    -> False
    isPerfectNumber 28   -> True
    isPerfectNumber 500  -> False
-}
isPerfectNumber :: Integer -> Bool
isPerfectNumber n = n == sumDivisors 1 0 where
    sumDivisors i res
        | i >= n            = res
        | n `mod` i == 0    = sumDivisors (i + 1) (res + i)
        | otherwise         = sumDivisors (i + 1) res

{-
Задача 6. Да се дефинира функция interval a b, която връща списък с числата в
интервала [a .. b] (за целта НЕ може да използвате израза [a .. b]).

Примери:
    interval 1 4 -> [1, 2, 3, 4]
    interval 2 5 -> [2, 3, 4, 5]
    interval 5 2 -> []
-}
interval :: Integer -> Integer -> [Integer]
interval a b =
    if a > b
        then []
        else a : interval (a+1) b

{-
Задача 7. Да се дефинира функция digits n, която връща списък с цифрите на
цялото число n >= 0.

Примери:
    digits 1234 -> [1, 2, 3, 4]
    digits 1750 -> [1, 7, 5, 0]
-}
digits :: Integer -> [Integer]
digits n = reverse (helper n) where
    helper n
        | n < 0     = error "n < 0"
        | n < 10    = [n]
        | otherwise = (n `mod` 10) : helper (n `div` 10)

digits' :: Integer -> [Integer]
digits' n
    | n < 0  = error "n < 0"
    | n < 10 = [n]
    | otherwise = digits' (n `div` 10) ++ [n `mod` 10]

{-
Задача 8. Да се дефинира функция removeDuplicates xs, която приема списък от
числа xs, и връща списък от числа, в който са премахнати всички дупликати в xs.

Примери:
    removeDuplicates [1, 2, 1] -> [1, 2]
    removeDuplicates [1, 3, 7, 3, 5, 1] -> [1, 3, 7, 5]
-}
removeDuplicates :: [Integer] -> [Integer]
removeDuplicates xs = reverse (helper xs []) where
    helper items res
        | null items                = res
        | (head items) `elem` res   = helper (tail items) res
        | otherwise                 = helper (tail items) (head items:res)

{-
Задача 9. Напишете функцията joinWords c strs, която слива няколко думи в една,
използвайки за разделител символ c.

Примери:
    joinWords ' ' ["The", "Sound", "of", "Silence"] -> "The Sound of Silence"
    joinWords ',' ["One", "Two", "Three", "Four"] -> "One,Two,Three,Four"
-}
joinWords :: Char -> [String] -> String
joinWords _ [] = ""
joinWords _ (x:[]) = x
joinWords c (x:xs) = x ++ [c] ++ joinWords c xs

joinWords' :: Char -> [String] -> String
joinWords' c strs
    | null strs = ""
    | length strs == 1 = head strs
    | otherwise = head strs ++ [c] ++ joinWords' c (tail strs)

{-
Задача 10. Дефинирайте функцията indices x xs, която връща всички индекси на елементи
от списъка xs, чиято стойност е равна на x.

Примери:
    indices 1 [1, 2, 3, 1, 4] -> [0, 3]
    indices 1 [] -> []
-}
indices :: Eq a => a -> [a] -> [Int]
indices x xs = [i | (i, x') <- zip [0..] xs, x' == x]

{-
Задача 11. Разлика на множества: дефинирайте функцията diff xs ys,
която приема два списъка, във всеки от които няма повтарящи се елементи
и връща разликата между първия и втория, т.е. всички елементи от първия
списък, които не се съдържат във втория.

Пример:
    diff [1, 2, 3] [1, 3, 7] -> [2]
-}
diff :: Eq a => [a] -> [a] -> [a]
diff xs ys = filter (\x -> not (x `elem` ys)) xs

{-
Задача 12. Хетерограми: дефинирайте функцията isHeterogram str, която проверява дали
символният низ str e хетерограма. Хетерограма се нарича символен низ, в който всеки
символ се среща само по веднъж.

Примери:
    isHeterogram "abcd" -> True
    isHeterogram "abbd" -> False
-}
isHeterogram :: String -> Bool
isHeterogram str = and [length (filter (== c) str) == 1 | c <- str]

{-
Задача 13. Напишете функцията argmin f xs, която връща елемента x от списъка xs, която
минимизира функцията f, т.е. това x при което f x има най-малка стойност.

Пример:
    Ако имаме people = [("Alice", 23), ("Bob", 19), ("Cyril", 21)] и искаме да върнем наредената двойка
    от имена и възрасти с най-малка стойност, то можем да извикаме:
    
    argmin snd people                   -> ("Bob", 19)
    argmin (\(_, age) -> age) people    -> ("Bob", 19)
-}
argmin :: Ord b => (a -> b) -> [a] -> a
argmin f xs = head [x | x <- xs, f x == fmin] where
    fmin = minimum (map f xs)

{-
Задача 14. Нека са дадени множествата xs и ys, и едноаргументата функция f от xs към ys.
Ще наричаме множеството ys образ на xs през f, тогава и само тогава когато за всяко x от xs,
f(x) принадлежи на ys и за всяко y от ys, съществува x, елемент на xs, за който f(x) = y.

Дефинирайте функцията isImageOf f xs ys, която връща дали ys е образ на xs през f.
-}
-- "преписваме" условието на задачата на Хаскел
isImageOf :: Eq b =>  (a -> b) -> [a] -> [b] -> Bool
isImageOf f xs ys = and [fx `elem` ys | fx <- fxs] && and [y `elem` fxs | y <- ys] where
    fxs = map f xs

{-
Задача 15. Напишете функцията maximize, която получава непразен списък от едноместни
числови функции и връща нова едноместна числова функция на аргумент x, която дава 
стойността f x на тази фунция f от списъка, за която числото f x е най-голямо 
по абсолютна стойност.

Пример: 
    maximize [(\x -> x ** 3), (\x -> x + 1)] 0.5 = 1.5
    maximize [(\x -> x ** 3), (\x -> x + 1), (\x -> x ** 4)] (-2) = 16
-}
maximize :: [Double -> Double] -> (Double -> Double)
maximize [] _ = error "empty list!"
maximize [f] x = f x
maximize (f:fs) x = if abs fx > abs mfx then fx else mfx where
    fx = f x
    mfx = maximize fs x

{-
Задача 16. Дефинирайте функцията isPath adjs nodes, която приема списък на наследниците
на даден граф adjs и списък от върхове nodes и връща дали nodes е път в съответния граф.

Примери:
    isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 2, 4] -> True
    isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 3, 4] -> False
-}
findAssoc :: (Eq a) => [(a, b)] -> a -> b
findAssoc [] _ = error "not found!"
findAssoc ((k, v):xs) key
    | k == key  = v
    | otherwise = findAssoc xs key

findAssoc' xs key = head [v | (k, v) <- xs, k == key]

isPath :: (Eq a) => [(a, [a])] -> [a] -> Bool
isPath adjs nodes = and [to `elem` findAssoc adjs from | (from, to) <- zip nodes (drop 1 nodes)]

isPath' adjs (n1:n2:ns) = n2 `elem` findAssoc adjs n1 && isPath adjs (n2:ns)
isPath' adjs _ = True

{-
Задача 17*. Дефинирайте функцията simplePaths adjs k node, която приема списък на
наследниците adjs на даден ориентиран граф, цяло число k и идентификатор на връх
node и връща всички прости пътища с дължина k, които започват от node.

Примери:
    simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 0 1 -> [[1]]
    simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 1 -> [[1, 2], [1, 3]]
    simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 2 1 -> [[1, 2, 3], [1, 2, 4]]
-}
simplePaths :: (Eq a) => [(a, [a])] -> Int -> a -> [[a]]
simplePaths adjs k node
    | k < 0     = error "k >= 0"
    | k == 0    = [[node]]
    | otherwise = map (node:) $ filter (not . (node `elem`)) $ concat [simplePaths adjs (k - 1) n | n <- findAssoc adjs node]


-- извикване на примерите от условията:
main :: IO()
main = do 
    putStrLn "Exercise 1."
    print $ isLeapYear 1984 -- True
    print $ isLeapYear 1995 -- False
    print $ isLeapYear 2000 -- True
    print $ isLeapYear 2100 -- False
    putStrLn ""

    putStrLn "Exercise 2."
    print $ reverseDigits 0     -- 0
    print $ reverseDigits 5     -- 5
    print $ reverseDigits 12345 -- 54321
    print $ reverseDigits 1212  -- 2121
    print $ reverseDigits 1000  -- 1
    putStrLn ""

    putStrLn "Exercise 3."
    print $ isPrime 1   -- False
    print $ isPrime 2   -- True
    print $ isPrime 3   -- True
    print $ isPrime 52  -- False
    print $ isPrime 71  -- True
    putStrLn ""

    putStrLn "Exercise 4."
    print $ sumPrimes 1 10  -- 17
    print $ sumPrimes 2 5   -- 10
    putStrLn ""

    putStrLn "Exercise 5."
    print $ isPerfectNumber 6    -- True
    print $ isPerfectNumber 8    -- False
    print $ isPerfectNumber 28   -- True
    print $ isPerfectNumber 500  -- False
    putStrLn ""

    putStrLn "Exercise 6."
    print $ interval 1 4 -- [1, 2, 3, 4]
    print $ interval 2 5 -- [2, 3, 4, 5]
    print $ interval 5 2 -- []
    putStrLn ""

    putStrLn "Exercise 7."
    print $ digits 1234 -- [1, 2, 3, 4]
    print $ digits 1750 -- [1, 7, 5, 0]
    putStrLn ""

    putStrLn "Exercise 8."
    print $ removeDuplicates [1, 2, 1] -- [1, 2]
    print $ removeDuplicates [1, 3, 7, 3, 5, 1] -- [1, 3, 7, 5]
    putStrLn ""

    putStrLn "Exercise 9."
    print $ joinWords ' ' ["The", "Sound", "of", "Silence"] -- "The Sound of Silence"
    print $ joinWords ',' ["One", "Two", "Three", "Four"] -- "One,Two,Three,Four"
    putStrLn ""

    putStrLn "Exercise 10."
    print $ indices 1 [1, 2, 3, 1, 4] -- [0, 3]
    print $ indices 1 [] -- []
    putStrLn ""

    putStrLn "Exercise 11."
    print $ diff [1, 2, 3] [1, 3, 7] -- [2]
    putStrLn ""

    putStrLn "Exercise 12."
    print $ isHeterogram "abcd" -- True
    print $ isHeterogram "abbd" -- False
    putStrLn ""

    putStrLn "Exercise 13."
    let people = [("Alice", 23), ("Bob", 19), ("Cyril", 21)] in do
        print $ argmin snd people                   -- ("Bob", 19)
        print $ argmin (\(_, age) -> age) people    -- ("Bob", 19)
    putStrLn ""

    -- Няма примери!
    -- putStrLn "Exercise 14."
    -- putStrLn ""

    putStrLn "Exercise 15."
    print $ maximize [(\x -> x ** 3), (\x -> x + 1)] 0.5 -- 1.5
    print $ maximize [(\x -> x ** 3), (\x -> x + 1), (\x -> x ** 4)] (-2) -- 16
    putStrLn ""

    putStrLn "Exercise 16."
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 2, 4] -- True
    print $ isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 3, 4] -- False
    putStrLn ""

    putStrLn "Exercise 17."
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 0 1 -- [[1]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 1 -- [[1, 2], [1, 3]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 2 1 -- [[1, 2, 3], [1, 2, 4]]
    putStrLn ""
