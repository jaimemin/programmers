-- 코드를 작성해주세요
WITH RECURSIVE ECOLI_GENERATIONS AS 
(
    SELECT 
        ID,
        PARENT_ID,
        1 AS GENERATION
    FROM 
        ECOLI_DATA
    WHERE 
        PARENT_ID IS NULL
    UNION ALL
    (
        SELECT
            e.ID,
            e.PARENT_ID,
            eg.GENERATION + 1 AS GENERATION
        FROM 
            ECOLI_DATA e
        INNER JOIN 
            ECOLI_GENERATIONS eg 
        ON 
            e.PARENT_ID = eg.ID
    )
)

# SELECT
#     *
# FROM
#     ECOLI_GENERATIONS

SELECT 
    COUNT(ID) AS COUNT,
    GENERATION
FROM 
    ECOLI_GENERATIONS
WHERE 
    ID NOT IN 
    (
        SELECT 
            DISTINCT PARENT_ID 
        FROM 
            ECOLI_DATA 
        WHERE 
            PARENT_ID IS NOT NULL
    )
GROUP BY 
    GENERATION
ORDER BY 
    GENERATION;
