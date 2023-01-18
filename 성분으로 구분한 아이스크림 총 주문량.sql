-- 코드를 입력하세요
SELECT
    INGREDIENT_TYPE,
    SUM(TOTAL_ORDER) AS TOTAL_ORDER
FROM
    FIRST_HALF
INNER JOIN
    ICECREAM_INFO
ON
    FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR
GROUP BY
    INGREDIENT_TYPE
ORDER BY
    TOTAL_ORDER ASC
