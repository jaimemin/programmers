-- 코드를 입력하세요
SELECT
    BOOK.AUTHOR_ID,
    AUTHOR.AUTHOR_NAME,
    BOOK.CATEGORY,
    SUM(BOOK.PRICE * BOOK_SALES.SALES) AS TOTAL_SALES
FROM
    BOOK
INNER JOIN
    AUTHOR
ON
    BOOK.AUTHOR_ID = AUTHOR.AUTHOR_ID
INNER JOIN
    BOOK_SALES
ON
    BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
WHERE
    BOOK_SALES.SALES_DATE >= '2022-01-01'
AND
    BOOK_SALES.SALES_DATE < '2022-02-01'
GROUP BY
    BOOK.AUTHOR_ID,
    BOOK.CATEGORY
ORDER BY
    BOOK.AUTHOR_ID ASC,
    BOOK.CATEGORY DESC
