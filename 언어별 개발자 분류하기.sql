WITH tbl_skill_code AS (
    SELECT 
        MAX(CASE WHEN NAME = 'Python' THEN CODE ELSE 0 END) AS python_code,
        SUM(CASE WHEN CATEGORY = 'Front End' THEN CODE ELSE 0 END) AS frontend_code,
        MAX(CASE WHEN NAME = 'C#' THEN CODE ELSE 0 END) AS csharp_code
    FROM SKILLCODES
),
GRADED_DEVELOPERS AS (
    SELECT
        ID,
        EMAIL,
        CASE
            WHEN (SKILL_CODE & (SELECT python_code FROM tbl_skill_code)) > 0
                 AND (SKILL_CODE & (SELECT frontend_code FROM tbl_skill_code)) > 0 THEN 'A'
            WHEN (SKILL_CODE & (SELECT csharp_code FROM tbl_skill_code)) > 0 THEN 'B'
            WHEN (SKILL_CODE & (SELECT frontend_code FROM tbl_skill_code)) > 0 THEN 'C'
            ELSE NULL
        END AS GRADE
    FROM DEVELOPERS
)

SELECT 
    GRADE,
    ID,
    EMAIL
FROM 
    GRADED_DEVELOPERS
WHERE 
    GRADE IS NOT NULL
ORDER BY 
    GRADE, ID;
