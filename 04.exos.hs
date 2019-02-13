{-
Задача 1. Да се дефинира функцията isLeapYear year, която проверява дали годината year
е високосна.

ПримерИ:
    isLeapYear 1984 -> True
    isLeapYear 1995 -> False
    isLeapYear 2000 -> True
    isLeapYear 2100 -> False
-}
isLeapYear :: Integer -> Bool
isLeapYear year = undefined

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
reverseDigits n = undefined

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
isPrime n = undefined

{-
Задача 4. Дефинирайте функцияга sumPrimes a b, която връща сумата на всички прости числа
в интервала от a до b.

Примери:
    sumPrimes 1 10  -> 17
    sumPrimes 2 5   -> 10
-}
sumPrimes :: Integer -> Integer -> Integer
sumPrimes a b = undefined

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
isPerfectNumber n = undefined

{-
Задача 6. Да се дефинира функция interval a b, която връща списък с числата в
интервала [a .. b] (за целта НЕ може да използвате израза [a .. b]).

Примери:
    interval 1 4 -> [1, 2, 3, 4]
    interval 2 5 -> [2, 3, 4, 5]
    interval 5 2 -> []
-}
interval :: Integer -> Integer -> [Integer]
interval a b = undefined

{-
Задача 7. Да се дефинира функция digits n, която връща списък с цифрите на
цялото число n >= 0.

Примери:
    digits 1234 -> [1, 2, 3, 4]
    digits 1750 -> [1, 7, 5, 0]
-}
digits :: Integer -> [Integer]
digits n = undefined

{-
Задача 8. Да се дефинира функция removeDuplicates xs, която приема списък от
числа xs, и връща списък от числа, в който са премахнати всички дупликати в xs.

Примери:
    removeDuplicates [1, 2, 1] -> [1, 2]
    removeDuplicates [1, 3, 7, 3, 5, 1] -> [1, 3, 7, 5]
-}
removeDuplicates :: [Integer] -> [Integer]
removeDuplicates xs = undefined

{-
Задача 9. Напишете функцията joinWords c strs, която слива няколко думи в една,
използвайки за разделител символ c.

Примери:
    joinWords ' ' ["The", "Sound", "of", "Silence"] -> "The Sound of Silence"
    joinWords ',' ["One", "Two", "Three", "Four"] -> "One,Two,Three,Four"
-}
joinWords :: Char -> [String] -> String
joinWords sep words = undefined

{-
Задача 10. Дефинирайте функцията indices x xs, която връща всички индекси на елементи
от списъка xs, чиято стойност е равна на x.

Примери:
    indices 1 [1, 2, 3, 1, 4] -> [0, 3]
    indices 1 [] -> []
-}
indices :: Eq a => a -> [a] -> [Int]
indices x xs = undefined

{-
Задача 11. Разлика на множества: дефинирайте функцията diff xs ys,
която приема два списъка, във всеки от които няма повтарящи се елементи
и връща разликата между първия и втория, т.е. всички елементи от първия
списък, които не се съдържат във втория.

Пример:
    diff [1, 2, 3] [1, 3, 7] -> [2]
-}
diff :: Eq a => [a] -> [a] -> [a]
diff xs ys = undefined

{-
Задача 12. Хетерограми: дефинирайте функцията isHeterogram str, която проверява дали
символният низ str e хетерограма. Хетерограма се нарича символен низ, в който всеки
символ се среща само по веднъж.

Примери:
    isHeterogram "abcd" -> True
    isHeterogram "abbd" -> False
-}
isHeterogram :: String -> Bool
isHeterogram str = undefined

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
argmin f xs = undefined

{-
Задача 14. Нека са дадени множествата xs и ys, и едноаргументата функция f от xs към ys.
Ще наричаме множеството ys образ на xs през f, тогава и само тогава когато за всяко x от xs,
f(x) принадлежи на ys и за всяко y от ys, съществува x, елемент на xs, за който f(x) = y.

Дефинирайте функцията isImageOf f xs ys, която връща дали ys е образ на xs през f.
-}
-- "преписваме" условието на задачата на Хаскел
isImageOf :: Eq b =>  (a -> b) -> [a] -> [b] -> Bool
isImageOf f xs ys = undefined

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
maximize fxs = undefined

{-
Задача 16. Дефинирайте функцията isPath adjs nodes, която приема списък на наследниците
на даден граф adjs и списък от върхове nodes и връща дали nodes е път в съответния граф.

Примери:
    isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 2, 4] -> True
    isPath [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] [1, 3, 4] -> False
-}
isPath :: (Eq a) => [(a, [a])] -> [a] -> Bool
isPath adjs nodes = undefined

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
simplePaths adjs k node = undefined


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
