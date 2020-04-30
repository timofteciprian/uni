function joc() {
    let matrice = [
        [1, 2, 5, 4],
        [7, 8, 4, 5],
        [8, 3, 1, 6],
        [7, 3, 2, 6]
    ];

    const main = document.getElementById('main');
    let firstSelection = '';
    let secondSelection = '';
    main.innerHTML = '';
    const table = document.createElement('table');
    main.appendChild(table);
    matrice.forEach((row) => {
        const newRow = document.createElement('tr');
        row.forEach((value) => {
            const newCell = document.createElement('td');
            newCell.innerHTML = value;
            newCell.style.border = '1px solid black';
            newCell.style.fontSize = '25px';
            newCell.style.padding = '5px 15px 5px 15px';
            newCell.style.color = 'white';
            newCell.onclick = () => {
                newCell.style.color = 'black';
                if (firstSelection === '') {
                    firstSelection = newCell.innerText;
                    newCell.style.backgroundColor = 'grey';
                    firstCell = newCell
                } else {
                    secondSelection = newCell.innerText;
                    if (firstSelection === secondSelection) {
                        newCell.style.backgroundColor = 'green';
                        firstCell.style.backgroundColor = 'green';
                        firstSelection = '';
                        secondSelection = '';
                    } else {
                        newCell.style.backgroundColor = 'grey';
                        setTimeout(() => {
                            newCell.style.backgroundColor = 'white';
                            firstCell.style.backgroundColor = 'white';
                            newCell.style.color = 'white';
                            firstCell.style.color = 'white';
                            firstSelection = '';
                            secondSelection = '';
                        }, 1000);
                    }
                }
            };
            newRow.appendChild(newCell)
        });
        table.appendChild(newRow)
    })
}


window.onload = function(){
    joc();
};
