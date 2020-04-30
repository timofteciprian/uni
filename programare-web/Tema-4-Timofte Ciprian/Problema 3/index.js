function joc() {
    let firstSelection = '';
    let secondSelection = '';
    $('#main').html('')
    let matrice = [
        [7, 8, 1, 5],
        [6, 3, 4, 3],
        [8, 4, 7, 2],
        [1, 5, 5, 2]
    ];
    $('<table id="Table"></table>').appendTo('#main');
    matrice.forEach((row) => {
        let newRow = $('<tr></tr>');
        row.forEach((value) => {
            let newCell = $('<td></td>');
            newCell.html(value);
            newCell.css('border','2px solid black');
            newCell.css('fontSize', '25px');
            newCell.css('padding', '5px 15px 5px 15px');
            newCell.css('color', 'white');
            newCell.click(() => {
                newCell.css('color', 'black');
                if (firstSelection === '') {
                    firstSelection = newCell.html();
                    newCell.css('backgroundColor', 'grey');
                    firstCell = newCell
                } else {
                    secondSelection = newCell.html();
                    if (firstSelection === secondSelection) {
                        newCell.css('backgroundColor', 'green');
                        firstCell.css('backgroundColor', 'green');
                        firstSelection = '';
                        secondSelection = '';
                    } else {
                        newCell.css('backgroundColor', 'grey');
                        setTimeout(() => {
                            newCell.css('backgroundColor', 'white');
                            firstCell.css('backgroundColor', 'white');
                            newCell.css('color', 'white');
                            firstCell.css('color', 'white');
                            firstSelection = '';
                            secondSelection = '';
                        }, 1000);
                    }
                }
            });
            newRow.append(newCell)
        });
        $('#Table').append(newRow);
    })
}


window.onload = function () {
    joc();
};
