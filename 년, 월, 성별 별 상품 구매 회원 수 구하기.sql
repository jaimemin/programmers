-- 코드를 입력하세요
SELECT
    YEAR(ONLINE_SALE.SALES_DATE) AS YEAR,
    MONTH(ONLINE_SALE.SALES_DATE) AS MONTH,
    USER_INFO.GENDER,
    COUNT(DISTINCT USER_INFO.USER_ID) AS USERS
FROM
    USER_INFO
INNER JOIN
    ONLINE_SALE
ON
    USER_INFO.USER_ID = ONLINE_SALE.USER_ID
WHERE
    USER_INFO.GENDER IN (0, 1)
GROUP BY
    YEAR,
    MONTH,
    USER_INFO.GENDER
ORDER BY
    YEAR ASC,
    MONTH ASC,
    USER_INFO.GENDER ASC
