-- #보호소에서 중성화한 동물 59045
SELECT I.ANIMAL_ID, I.ANIMAL_TYPE, I.NAME 
FROM ANIMAL_INS as I JOIN ANIMAL_OUTS as O 
WHERE I.ANIMAL_ID = O.ANIMAL_ID AND I.SEX_UPON_INTAKE != O.SEX_UPON_OUTCOME
ORDER BY I.ANIMAL_ID

-- #입양 시각 구하기(2) 59413
-- @see : set을 이용해서 변수 생성 가능
set @hour = -1;
select @hour:=@hour+1 as HOUR, (
    select count(datetime)
    from animal_outs
    where hour(datetime) = @hour
) as COUNT
from animal_outs
where @hour < 23;

-- group by를 이용한 방법
-- /* 
--  * @see : with recursive 는 mysql 5.7 이하는 미지원
--  * 재귀 쿼리를 이용하여 실제로 테이블을 생성하거나 가상테이블을 생성하는 방법
--  */
with recursive time as ( -- time 이라는 가상 테이블 생성
    select 0 as h 
    union all
    select h+1 from time where h < 23
    -- time은 0부터 23까지의 데이터를 h라는 칼럼에 갖음
)
select h, count(datetime) 
from time left join animal_outs -- time과 animal_outs를 left outer join 하여 count를 구함, null인 경우 -> 0
on h = hour(datetime)
group by h
order by h;

-- #