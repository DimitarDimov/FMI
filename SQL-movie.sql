--SELECT name,  sum(length) FROM movieexec JOIN movie ON producerc# = cert#
--WHERE CERT# IN (SELECT PRODUCERC# FROM MOVIE WHERE YEAR < 1980)
--GROUP BY name

--SELECT starname, title, name, networth
--FROM starsin JOIN movie ON movietitle=title AND movieyear=year
--	JOIN (SELECT cert#, networth, name FROM movieexec WHERE networth = (SELECT max(networth) FROM MOVIEEXEC)) t
--	ON t.CERT# = PRODUCERC#;