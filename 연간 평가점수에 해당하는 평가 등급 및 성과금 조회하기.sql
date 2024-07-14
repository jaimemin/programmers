-- 코드를 작성해주세요
WITH Avg_Scores AS (
    SELECT 
        EMP_NO, 
        AVG(SCORE) AS AVG_SCORE
    FROM 
        HR_GRADE
    WHERE 
        YEAR = 2022
    GROUP BY 
        EMP_NO
),
Grades AS (
    SELECT 
        EMP_NO, 
        CASE 
            WHEN AVG_SCORE >= 96 THEN 'S'
            WHEN AVG_SCORE >= 90 THEN 'A'
            WHEN AVG_SCORE >= 80 THEN 'B'
            ELSE 'C'
        END AS GRADE
    FROM 
        Avg_Scores
),
Bonuses AS (
    SELECT 
        E.EMP_NO, 
        EMP_NAME, 
        GRADE,
        CASE 
            WHEN GRADE = 'S' THEN SAL * 0.20
            WHEN GRADE = 'A' THEN SAL * 0.15
            WHEN GRADE = 'B' THEN SAL * 0.10
            ELSE 0
        END AS BONUS
    FROM 
        HR_EMPLOYEES E
    INNER JOIN 
        Grades G
    ON 
        E.EMP_NO = G.EMP_NO
)

SELECT 
    EMP_NO, 
    EMP_NAME, 
    GRADE, 
    BONUS
FROM 
    Bonuses
ORDER BY 
    EMP_NO ASC;
