-- #최솟값 구하기 59038
-- datetime을 기준으로 오름차순 정렬하여 가장 최근 값 값 1개 출력
SELECT datetime FROM animal_ins ORDER BY datetime ASC LIMIT 1;

-- #동물 수 구하기 59406
SELECT count(animal_id) FROM animal_ins;

-- #GROUP BY
-- #고양이와 개는 몇마리 있을까 59040
SELECT animal_type, count(animal_type) FROM animal_ins GROUP BY animal_type ORDER BY animal_type;

-- #동명 동물 찾기 59041
SELECT name, count(name)AS COUNT FROM animal_ins 
GROUP BY NAME HAVING NAME is not null AND COUNT >= 2 ORDER BY name;

-- #입양 시각 구하기 59412
SELECT hour(datetime) HOUR, count(datetime) COUNT FROM animal_outs 
GROUP BY hour(datetime) HAVING HOUR >= 9 AND HOUR <= 19
ORDER BY HOUR asc;

-- #null 처리하기 59410
-- @see : mysql은 ifnull(칼럼, 대체문자열)함수로 칼럼 값이 null인 경우 대체문자열 넣어줌
SELECT animal_type, IFNULL(name, 'No name')name, sex_upon_intake FROM animal_ins;


-- #datetime -> date로 변환하기 59414
-- @see : date_foramt(칼럼, 새 포맷)함수로 포맷을 변경하여 출력 가능
SELECT animal_id, name, date_format(datetime, '%Y-%m-%d')as '날짜' 
FROM animal_ins ORDER BY animal_id;

-- #중복저게하기 59408
SELECT count(DISTINCT name)AS count FROM animal_ins;

-- #이름에 el이 들어가는 동물 찾기 59047
SELECT animal_id, name FROM animal_ins 
WHERE name like '%el%' AND animal_type = 'Dog' ORDER BY name asc;

-- #루시와 엘라 찾기 59046
SELECT animal_id, name, sex_upon_intake FROM animal_ins 
WHERE name IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty') ORDER BY animal_id;

-- #중성화 여부 파악하기 59409
-- @see : select문에 if문을 이용하면 sex_upon_intake 값의 조건에 따라 X 혹은 O 의 값을 보여줌
--        AS하면 새 칼럼명으로 보여줌
SELECT animal_id, name, IF(sex_upon_intake LIKE 'Intact%', 'X', 'O') AS '중성화' 
FROM animal_ins