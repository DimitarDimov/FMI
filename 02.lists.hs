{- Основни операции върху списъци -}
main :: IO()
main = 
    let                            {- Няколко начина за създаване на списъци -}
        xs = [1, 2, 3, 4, 5]       -- директно изброяване на елементите
        bs = 123 : xs              -- добавяне на елемент в началото
--        XXX = xs : 123           -- но НЕ и в края
        cs = [1 .. 10]             -- използване на интервал (range)
        ds = [1, 3 .. 10]          -- интервал със стъпка: в случая 3 - 1 = 2.
        es = xs ++ bs ++ cs        -- слепване на два или повече списъка

                                   {- Можете също така да създавате и "безкрайни" списъци -}
        fs = [1 ..]                -- безкраен range
        gs = [1, 3 ..]             -- безкраен range със стъпка
        hs = repeat 1              -- повтаряне на даден елемент безкрайно
        is = cycle xs              -- безкрайно "циклене" по оригиналния списък
    in do
        print $ xs          -- [1, 2, 3, 4, 5]
        print $ bs          -- [123, 1, 2, 3, 4, 5]
        print $ cs          -- [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        print $ ds          -- [1, 3, 5, 7, 9]
        print $ es          -- [1, 2, 3, 4, 5, 123, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

        -- take n xs връща първите n елемента на xs
        print $ take 2 xs   -- [1, 2]
        print $ take 10 xs  -- [1, 2, 3, 4, 5]
       -- можете да вземете първите n елемента на безкраен списък
        print $ take 5 fs   -- [1, 2, 3, 4, 5]
        print $ take 5 gs   -- [1, 2, 3, 7, 9]
        print $ take 7 hs   -- [1, 1, 1, 1, 1, 1, 1]
        print $ take 7 is   -- [1, 2, 3, 4, 5, 1, 2]

        -- drop n xs връша всички БЕЗ първите n елемента от xs
        print $ drop 2 xs   -- [3, 4, 5]
        print $ drop 10 xs  -- []

        -- head xs връша първия елемент
        -- tail xs връша всички БЕЗ първия елемент
        print $ head xs     -- 1
        print $ tail xs     -- [2, 3, 4, 5]

        -- last xs връща последния елемент 
        -- init xs връща всички БЕЗ последния елемент
        print $ last xs     -- 5
        print $ init xs     -- [1, 2, 3, 4]

        -- тези връшат грешка: Exception: Prelude.head: empty list
--        print $ head []
--        print $ last []

        -- length xs връща дължината на списъка
        print $ length xs   -- 5

        -- null xs връща дали списъкът е празен
        print $ null xs     -- False
        print $ null []     -- True

        -- reverse xs обръща списъка
        print $  reverse xs  -- [5, 4, 3, 2, 1]

        -- minimum, maximum, sum, product
        print $ minimum xs  -- 1
        print $ maximum xs  -- 5
        print $ sum xs      -- 1+2+3+4+5
        print $ product xs  -- 1*2*3*4*5

        -- xs !! n връща n-тия елемент от списъка (като xs[n] в C/C++)
        print $ xs !! 3     -- 4 (списъците се индексират от 0, както в C/C++)
--        print $ xs !! 10  -- ако се опитаме да вземем елемент след края на списъка ще получим: Prelude.!!: index too large
        
        -- x `elem` xs ни казва дали x е елемент на списъка xs
        print $ 2 `elem` xs     -- True
        print $ 10 `elem` xs    -- False

        -- takeWhile, dropWhile
        print $ takeWhile (\x -> x < 3) xs  -- [1, 2]
        print $ dropWhile (\x -> x < 3) xs  -- [3, 4, 5]

        -- concat [xs] - слепва списък от списъци в един общ списък
        print $ concat [xs, xs, xs]         -- [1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5]

        -- map fn xs връща списък съдържащ резултата от извикването на fn върхи всяко x в оризгиналния списък xs.
        print $ map (\x -> 2 * x) xs        -- [2, 4, 6, 8, 10]
        print $ map (2 *) xs                -- същото като предишното
        print $ [2 * x | x <- xs]           -- същото като предните две

        -- filter predicate xs връща под-списък съдържащ всички елементи на xs, за които предикатът е верен
        print $ filter (\x -> x `mod` 2 == 0) xs    -- [2, 4]
        print $ filter even xs                      -- същото като предишното
        print $ [x | x <- xs, even x]               -- [x for x in xs if even(x)] (така се пише на Python :))

        -- foldr and foldl fn initial xs взимат функция fn, първоначална стойност initial и списък xs
        -- и "редуцират" списъка посредством функцията fn
        -- Примери:
        --   mysum xs = foldr (+) 0 xs
        --   myproduct xs = foldr (*) 1 xs
        --   myconcat = foldr (++) [] -- the magic of currying
        print $ foldr (+) 0 xs  -- същото като sum xs
        print $ foldl (+) 0 xs  -- същото като sum xs
        print $ foldr (*) 1 xs  -- същото като product xs
        print $ foldl (*) 1 xs  -- същото като product xs
        -- foldr може да оперира и върху безкрайни списъци, докато foldl ще влезе в безкрайна рекурсия.
        print $ take 15 (foldr (++) [] (repeat xs))     -- това работи
--        print $ take 15 (foldl (++) [] (cycle [xs]))  -- това влиза в БЕЗКРАЙНА РЕКУРСИЯ!
        -- Ако не сте сигурни, то почти винаги трябва да използвате foldr.

        -- zip xs ys взима два списъка и връща списък с последователните двойки от елементите им.
        print $ zip xs "abcde" -- [(1, 'a'), (2, 'b'), (3, 'c'), (4, 'd'), (5, 'e')]
        -- zip приключва, когато сме взели всички елементи от по-краткия от двата списъка
        -- това ни позволява един от спицъте да бъде безкраен
        print $ zip xs [1 .. ] -- [(1, 1), (2, 2), (3, 3), (4, 4), (5, 5)]

        -- unzip прави обратното на zip
        print $ unzip [(1, 'a'), (2, 'b'), (3, 'c')] -- ([1, 2, 3], "abc")

        let fibs = 0:1:zipWith (+) fibs (tail fibs) in do
            -- Тук fibs съдържа ВСИЧКИ числа на Фибоначи. 
            -- тъй като Haskell е мързелив (lazy) език, той не се опитва да изчисли стойността 
            -- на даден елемент от списъка докато изрично не му я поискаме! 
            print $ take 100 fibs     -- първите 100 прости числа
            print $ fibs !! 0         -- 1-вото число на Фибоначи
            print $ fibs !! 127       -- 128-то число на Фибоначи
