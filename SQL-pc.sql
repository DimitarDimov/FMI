
select *
from laptop l inner join product p on l.model=p.model
where maker not in(select maker from product where type='Printer' group by maker having count(*)>3)