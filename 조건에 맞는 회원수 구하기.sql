-- 코드를 입력하세요
SELECT
    COUNT(*)
FROM
    USER_INFO
WHERE
    AGE >= 20
AND
    AGE < 30
AND
    JOINED LIKE '2021%'
