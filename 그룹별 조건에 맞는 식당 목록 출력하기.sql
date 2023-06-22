-- 코드를 입력하세요
WITH REVIEW_COUNTS AS (
    SELECT
        MEMBER_ID,
        COUNT(*) AS CNT
    FROM
        REST_REVIEW
    GROUP BY
        MEMBER_ID
    ORDER BY
        CNT DESC
    LIMIT
        1
),
MEMBER_IDS AS (
    SELECT
        MEMBER_ID,
        COUNT(*) AS CNT
    FROM
        REVIEW_COUNTS
    WHERE
        CNT = (SELECT CNT FROM REVIEW_COUNTS)
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
