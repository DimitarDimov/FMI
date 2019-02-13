--select name
--from ships
--where LAUNCHED in (select year(date) from BATTLES)

--select name
--from ships
--where launched = any (select year(date) from battles where count(*) >=1)

--select distinct ships.name
--from battles, ships
--where launched = year(date)

--select name
--from battles
--where exists (select distinct * from ships where year(date) = launched)

--select distinct name
--from ships
--join battles on launched = year(date)

--select distinct classes.COUNTRY,
--sunk_cnt
--from classes
--right join (select country, count(*) as sunk_cnt
--			from classes c
--			join ships s
--			on c.class = s.class
--			join outcomes o
--			on s.name = o.ship
--			where result = 'sunk'
--			group by country) sunk
--	on classes.country < sunk.COUNTRY
--	where sunk_cnt <= 3

--select *,
--	(select count(*)
--	 from classes c2 join ships s on c2.class = s.class
--	 join outcomes o on s.name = o.ship
--	 where c2.country = c.country and result = 'sunk')
-- from classes c
-- where (select count(*)
--		from classes c2 join ships s on c2.class =s.class
--		where c2.COUNTRY = c.COUNTRY) <= 3

--SELECT COUNTRY, count(*), count(SHIPS.NAME)
--FROM CLASSES LEFT JOIN SHIPS ON CLASSES.CLASS = SHIPS.CLASS
--LEFT JOIN OUTCOMES ON OUTCOMES.SHIP = SHIPS.name
--WHERE result = 'sunk' OR result IS NULL
--GROUP BY country
--having count(*) <=3
--ORDER BY COUNTRY


--select country, count(RESULT)
--from classes c
--left join ships s
--on c.class = s.class
--left join outcomes o
--on s.name = o.ship
--where o.result = 'sunk' OR result IS NULL
--group by country
--having count(ship) <=3



