-- 코드를 작성해주세요
WITH CODES AS (
    SELECT 
        SUM(CODE) AS CODE_SUM
    FROM 
        SKILLCODES 
    WHERE
        NAME = 'C#'
    OR
        NAME = 'Python'
)

SELECT 
    ID, 
    EMAIL, 
    FIRST_NAME, 
    LAST_NAME
FROM 
    DEVELOPERS
WHERE 
    (SKILL_CODE & (SELECT CODE_SUM FROM CODES) != 0) 
ORDER BY 
    ID ASC;
