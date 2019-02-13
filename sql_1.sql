-- 9.2017
--SELECT name, country
--FROM ships LEFT JOIN outcomes ON name=ship
--JOIN classes ON ships.class=classes.class
--WHERE result <> 'sunk'OR result IS NULL;

--SELECT name, displacement, numguns
--FROM classes c JOIN ships s ON s.class=c.class
--WHERE displacement = (SELECT min(DISPLACEMENT) FROM classes) 
--	AND numguns = (SELECT max(NUMGUNS) FROM classes c1 WHERE c1.DISPLACEMENT = c.DISPLACEMENT)

--SELECT *
--FROM outcomes o1
--WHERE EXISTS (SELECT * 
--					 FROM outcomes o2
--					 WHERE o1.SHIP = o2.SHIP AND o1.BATTLE <> o2.BATTLE)

--4b

--07.2017
use movies

--SELECT studioname, title, year 
--FROM movie m WHERE year = (SELECT max(year) FROM movie WHERE m.studioname = studioname)

--SELECT name, sum(length) 
--FROM movieexec JOIN movie ON producerc# = cert#
--GROUP BY name
--HAVING min(year) < 1980;

--SELECT starname, title, name, networth
--FROM starsin JOIN movie ON movietitle=title AND movieyear=year
--			 JOIN (SELECT cert#, networth, name 
--			       FROM movieexec
--				   WHERE networth = (SELECT max(networth) FROM MOVIEEXEC)) t ON PRODUCERC# = t.CERT#;


--SELECT name, title, year
--FROM movie JOIN movieexec ON producerc#=cert#
--WHERE cert# IN (SELECT producerc#
--				   FROM movie
--				   WHERE title='Star Wars');