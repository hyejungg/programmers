-- # 상위 n개 레코드 출력 59405
-- datetime을 기준으로 오름차순 정렬하여 가장 오래된 동물 1마리 출력
-- LIMIT 1을 없애면? 가장 오래된 동물부터 출력
SELECT name FROM animal_ins ORDER BY datetime ASC LIMIT 1 

-- #최대값 구하기 59415
-- datetime을 기준으로 내림차순 정렬하여 가장 최근 값 값 1개 출력
SELECT datetime FROM animal_ins ORDER BY datetime DESC LIMIT 1;

-- #모든 레코드 조회하기 59034
SELECT * FROM animal_ins;

-- #이름이 없는 동물의 아이디 59039
SELECT animal_id FROM animal_ins WHERE isNULL(name);
-- SELECT animal_id FROM animal_ins WHERE name is null;

-- #이름이 있는 동물의 아이디 59407
SELECT animal_id FROM animal_ins WHERE name is not null;

-- #어린 동물 찾기 59037
SELECT animal_id, name FROM animal_ins WHERE intake_condition != "Aged";

-- #여러 기준으로 정렬하기 59404
SELECT animal_id, name, datetime FROM animal_ins ORDER BY name, datetime DESC;

-- #아픈 동물 찾기 59036
SELECT animal_id, name FROM animal_ins WHERE intake_condition = "Sick";

-- #도움ㄹ의 아이디와 이름 59403
SELECT animal_id, name FROM animal_ins;

-- #역순 출력하기 59035
SELECT name, datetime FROM animal_ins ORDER BY animal_id DESC;