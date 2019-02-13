import Data.Char



expandedAlphabet :: String
expandedAlphabet = help 'a' 'z' 1
 where
 help  :: Char -> Char -> Int -> String
 help c l i
  | l == 'z' && c == 'z' = (replicate i c) ++ (help (chr(ord c - 1)) 'a' (i-1))
  | l == 'z' = (replicate i c) ++ (help (chr(ord c + 1)) l (i+1))
  | l == 'a' && c == 'a' = (replicate i c) ++ (help (chr(ord c + 1)) 'z' (i+1))
  | l == 'a' = (replicate i c) ++ (help (chr(ord c - 1)) l (i-1))