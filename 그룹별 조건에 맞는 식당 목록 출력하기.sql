-- 코드를 입력하세요
WITH REVIEW_SCORES AS (
    SELECT
        MEMBER_ID,
        SUM(REVIEW_SCORE) AS REVIEW_SCORE
    FROM
        REST_REVIEW
    GROUP BY
        MEMBER_ID
),
MEMBER_IDS AS (
    SELECT
        MEMBER_ID
    FROM
        REVIEW_SCORES
    WHERE
        REVIEW_SCORE = (SELECT MAX(REVIEW_SCORE) FROM REVIEW_SCORES)
)

SELECT
    MEMBER_NAME,
    REVIEW_TEXT,
    SUBSTRING(REVIEW_DATE, 1, 10) AS REVIEW_DATE
FROM
    MEMBER_PROFILE
INNER JOIN
    REST_REVIEW
ON
    MEMBER_PROFILE.MEMBER_ID = REST_REVIEW.MEMBER_ID
WHERE
    MEMBER_PROFILE.MEMBER_ID IN (SELECT MEMBER_ID FROM MEMBER_IDS)
ORDER BY
    REVIEW_DATE,
    REVIEW_TEXT
