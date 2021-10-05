SELECT
    COUNT(*) AS count
FROM
    (
        SELECT
            NAME
        FROM
            ANIMAL_INS
        GROUP BY
            NAME
        HAVING
            NAME IS NOT NULL
    ) AS TEMP