-- #최솟값 구하기 59038
-- datetime을 기준으로 오름차순 정렬하여 가장 최근 값 값 1개 출력
SELECT datetime FROM animal_ins ORDER BY datetime ASC LIMIT 1;

-- #동물 수 구하기 59406
SELECT count(animal_id) FROM animal_ins;