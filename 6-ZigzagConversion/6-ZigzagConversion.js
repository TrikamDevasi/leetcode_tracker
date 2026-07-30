// Last updated: 30/07/2026, 10:25:28
function convert(s, numRows) {
    if (numRows === 1 || numRows >= s.length) return s;

    const rows = Array.from({ length: numRows }, () => "");
    let curRow = 0, goingDown = false;

    for (const char of s) {
        rows[curRow] += char;
        if (curRow === 0 || curRow === numRows - 1) {
            goingDown = !goingDown;  // flip direction at edges
        }
        curRow += goingDown ? 1 : -1;
    }

    return rows.join("");
}