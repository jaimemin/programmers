-- 코드를 작성해주세요
WITH Percentage AS 
(
    SELECT 
        ID,
        NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC) AS SIZE_GROUP
    FROM 
        ECOLI_DATA
),
ColonyNames AS (
    SELECT
        ID,
        CASE 
            WHEN SIZE_GROUP = 1 THEN 'CRITICAL'
            WHEN SIZE_GROUP = 2 THEN 'HIGH'
            WHEN SIZE_GROUP = 3 THEN 'MEDIUM'
            WHEN SIZE_GROUP = 4 THEN 'LOW'
        END AS COLONY_NAME
    FROM
        Percentage
)

SELECT 
    ED.ID,
    CN.COLONY_NAME
FROM 
    ECOLI_DATA ED
INNER JOIN 
    ColonyNames CN 
ON 
    ED.ID = CN.ID
ORDER BY 
    ED.ID;
