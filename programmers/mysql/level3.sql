-- #없어진 기록 찾기 59042
select b.animal_id, b.name 
from animal_ins a right join animal_outs b 
on b.animal_id = a.animal_id 
where a.animal_id is null
order by b.animal_id; 

-- #있었는데요 없었습니다. 59043
select a.animal_id, a.name
from animal_outs a right join animal_ins b
on a.animal_id = b.animal_id
where a.datetime < b.datetime
order by b.datetime; -- 주의! a.datetime으로 하면 정답 X. 보호시작일이 빠른 순부터 이므로

-- #오랜 기간 보호한 동물(1) 59044
select a.name, a.datetime
from animal_ins a left join animal_outs b
on a.animal_id = b.animal_id
where b.datetime is null
order by a.datetime
limit 3;  -- 3마리만 출력

-- #오랜 기간 보호한 동물(2) 59411
-- order by 안에서 칼럼끼리 - 가능 ..
select b.animal_id, b.name
from animal_ins a right join animal_outs b
on a.animal_id = b.animal_id
order by b.datetime - a.datetime desc  -- 보호 기간이(입양간 날짜.b - 보호 날짜.a) 길었던(desc)
limit 2;  -- 2마리만 출력

-- #헤비 유저가 소유한 장소 77487
-- 셀프조인 이용
-- 서브쿼리를 이용하여 host_id가 2개 이상인 host_id와 일치하는 경우만 출력
select p1.id, p1.name, p1.host_id 
from places p1 join (
    select host_id
    from places
    group by host_id
    having count(host_id) >= 2
) p2
on p1.host_id = p2.host_id
order by p1.id;

select id, name, host_id
from places
where host_id in (
    select host_id
    from places
    group by host_id
    having count(host_id) >= 2
)
order by id;

