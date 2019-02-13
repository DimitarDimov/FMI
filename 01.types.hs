-- Едноредовите коментари в Haskell се пишат така.

{-
A многоредовите коментари изглеждат ето така.

-- има същата роля като // в C/C++.
{- ... -} е същото като /* ... */ в C/C++ (ама по-яко ...)
-}


{- 
Кратък списък на основните типове в Хаскел и операциите върху тях:

A. Булеви стойности: Булевите стойности в Haskell са от тип Bool 
(подобно на bool в С/С++).

Могат да приемат стойностите True или False (true и false в С/С++). 

  Операции върху булеви променливи:
  &&  - логическо И   (същото като С/С++)
  ||  - логическо ИЛИ (същото като С/С++)
  not - логическо НЕ  (! в С/С++)
  
  and [Bool] - дали всички са Тrue
  or [Bool] - дали някоя е True


B. Числа: има два основни типа:

а). Челочислени стойности: 
  - Int (като в Java/C++), 
  - Integer: цели числа с неограничена точност.

б). Дробни числа: Float и Double (като float и double в C++)

Познатите ви от С/С++ аритметични операции работят *почти* както 
се очаква - за разлика от С/С++ НЕ може да прилагате аритметични 
операции върху числа от различен тип!

- За да конвертирате цяло към дробно число, използвайте функцията
fromIntegral.

- За да конвертирате дробно към цяло число, използвайте функциите:
  
  ceiling  -- ceiling 5.1 = 6;    ceiling 5.6 = 6;
  floor    -- floor   5.1 = 5;    floor   5.6 = 5;
  round    -- round   5.1 = 5;    round   5.6 = 6;

- Целочислено делене и остатък:
  div 5 2 == 5 `div` 2 = 2 -- 5 / 2
  mod 5 2 == 5 `mod` 2 = 1 -- 5 % 2

Вторият запис се счита за "по-четим" и е за предпочитане пред първия.


C. Списъци: могат да съдържат елементи от произволен тип, но всички елементи на
даден списък ТРЯБВА да бъдат от един и същи тип. Това определя и типа на самия 
списък. Например:
  [Int] e списък от цели числа (Int) - подобно на List<Integer> в Java, или std::vector<int> в C++.
  
  [[Double]] е списък от списъци от числа с плаваща запетая (Double) -
  List<List<Double>> в Java, std::vector<std::vector<double>> в C++.


По конвенция, в Хаскел имената на променливите, които са списъци винаги завършват 
с буквата 's' (както думите в множествено число в английскя език).

Някои основни операции върху списъци:

1. Създаване:

- директно изброяване на елементите:
  xs = [1, 2, 3, 4, 5]
  [] - създава празен списък

- дефиниране на интервал (range):
  [1 .. 10]                 -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

- интервал със стъпка (равна на разликата м/у първия и нулевия елементи):
  [1, 3 .. 10]              -> [1, 3, 5, 7, 9]


2. Добавяне на елементи:
- добавяне на елемент в началото:
  123 : xs                  -> [123, 1, 2, 3, 4, 5]

  Операторът (:) се нарича cons, съкратено от construct.

- слепване (конкатенация) на два или повече списъка:
  [1, 3, 5] ++ [2, 4, 6]    -> [1, 3, 5, 2, 4, 6]
  [11] ++ [22] ++ [33]      -> [11, 22, 33]

- В Хаскел няма оператор за добавяне в края на даден списък, но за целта 
  може да използвате следния "трик":
  xs ++ [345]               -> [1, 2, 3, 4, 5, 345]


3. Полезни функции: 

- null xs връща дали списъкът е празен:
  null [1, 2, 3, 4, 5]      -> False
  null []                   -> True

- length xs връща дължината на списъка:
  length [1, 2, 3, 4, 5]    -> 5
  length []                 -> 0

- head xs връща първия елемент на списъка (или грешка ако е празен!):
  head [1, 2, 3, 4, 5]      -> 1
  head []                   -> Exception: Prelude.head: empty list

- tail xs връща всички БЕЗ първия елемент:
  tail [1, 2, 3, 4, 5]      -> [2, 3, 4, 5]
  tail []                   -> []

- take n xs връща първите n елемента на xs:
  take 2 [1, 2, 3, 4, 5]    -> [1, 2]
  take 10 [1, 2, 3, 4, 5]   -> [1, 2, 3, 4, 5] - ако n >= length xs, take връща 
                                                 целия списък

- drop n xs връща всички БЕЗ първите n елемента от xs:
  drop 2 [1, 2, 3, 4, 5]    -> [3, 4, 5]
  drop 10 [1, 2, 3, 4, 5]   -> [] - ако n >= length xs, drop връща празен списък

- reverse xs връща списък с елементите в обратен ред:
  reverse [1, 2, 3, 4, 5]   -> [5, 4, 3, 2, 1]
  reverse []                -> []

- elem x xs ни казва дали x е елемент на списъка xs:
  2 `elem` [1, 2, 3, 4, 5]  -> True
  10 `elem` [1, 2, 3, 4, 5] -> False

- minimum, maximum, sum, product - правят, каквото очаквате:

  minimum [1, 2, 3, 4, 5]   -> 1
  minimum []                -> Exception: Prelude.minimum: empty list

  maximum [1, 2, 3, 4, 5]   -> 5
  maximum []                -> Exception: Prelude.maximum: empty list

  sum [1, 2, 3, 4, 5]       -> 15 = 1 + 2 + 3 + 4 + 5
  sum []                    -> 0

  product [1, 2, 3, 4, 5]   -> 120 = 1 * 2 * 3 * 4 * 5
  product []                -> 1


D. Вектори/Кортежи (tuples): има три основни разлики между векторите и списъците.

На практика най-често използваните вектори са двойките (pairs). Основните функции върху 
тях са fst и snd, които връщат съответно първия и втория елемент на двойката.

    fst (1, 2) -> 1
    snd (1, 2) -> 2


Едно интересно приложение на векторите е присвояването на няколко променливи наведнъж:
    (a, b, c) = (1, 3.14, "Kasa bira!")

което е (почти) същото като:
    a = 1
    b = 3.14
    c = "Kasa bira!"


Ето и няколко примера за типове на вектори:
 - (Ingeger, Bool) - вектор от цяло число и булева стойност. 
 - (String, Double) - вектор от символен низ и дробно число.
 - (Integer, [String], Double) - вектор от цяло число, масив от символни низове и дробно число.
 - ((String, Bool), [[Integer]]) - вектор от двойка от символен низ и булева стойност, и масив 
   от масиви от цели числа.


Е. Символи и символни низове.

1. Символите в Haskell са от тип Char (подобен на типа char в С/С++)

Полезни функции върху символи:

  ord c - връща ASCII кода на символа c. Пример: ord 'q' = 113
  chr n - връща символа с ASCII код n. Пример: chr 113 = 'q' 

  import Data.Char ви позволява да използвате следните полезни функции:

  toUpper c - обръща буквата c в главна.          
  Пример: toUpper 'Q' = 'Q';      toUpper 'q' = 'Q';      toUpper '1' = '1'
  
  toLower c - обръща буквата c в малка.           
  Пример: toLower 'Q' = 'q';      toLower 'q' = 'q';      toLower '1' = '1'
  
  isUpper c - проверява дали буквата c e главна.
  Пример: isUpper 'Q' = True;     isUpper 'q' = False;    isUpper '1' = False
  
  isLower c - проверява дали буквата c e малка.   
  Пример: isLower 'Q' = False;    isLower 'q' = True;     isLower '1' = False
  
  isAlpha c - проверява дали символът c е буква.  
  Пример: isAlpha 'Q' = True;     isAlpha 'q' = True;     isAlpha '1' = False
  
  isDigit c - проверява дали символът c e цифра.  
  Пример: isDigit 'Q' = False;    isDigit 'q' = False;    isDigit '1' = True
  
  isSpace c - проверява дали символът c e интервал.   
  Пример: isSpace ' ' = True;     isSpace '\t' = True;    isSpace 'q' = False
  
  isAlphaNum c - проверява дали символът c е буква или цифра.
  Пример: isAlphaNum ';' = False; isAlphaNum 'q' = True;  isAlphaNum '1' = True


2. Символният низ в Haskell е просто списък от символи, т.е. String = [Char].
   Следователно всички функции работещи върху списъци, работят и върху символни низове!


3. Функциите read и show:

  show a - връща стринговата репрезентация на а.
  Пример:
      show 123        = "123"
      show "123"      = "\"123\""
      show [1, 2, 3]  = "[1,2,3]"

  read s - конвертира символния низ s до стойност.
  Пример:
      read "123" :: Integer           = 123
      read "[1,2,3]" :: [Integer]     = [1, 2, 3]
-}

-- main функция, че да се компилира ;)
main :: IO()
main = do 
  print "Hello world."