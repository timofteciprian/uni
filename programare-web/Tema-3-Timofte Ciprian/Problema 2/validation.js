function validate() {
    inputs = Array.from(document.getElementsByTagName('input'))
    inputs.forEach((input) => {
        if (input.name === 'name') {
            if (/\d/.test(input.value)) {
                input.style.border = '2px solid green'
            } else {
                input.style.border = '2px solid red'
            }
        } else if (input.name === 'age') {
            if (isNumeric(input.value)) {
                input.style.border = '2px solid green'
            } else {
                input.style.border = '2px solid red'
            }
        } else if (input.name === 'email') {
            if (isEmail(input.value)) {
                input.style.border = '2px solid green'
            } else {
                input.style.border = '2px solid red'
            }
        } else if (input.name === 'birthday') {
            if (!isNaN(isDate(input.value))) {
                input.style.border = '2px solid green'
            } else {
                input.style.border = '2px solid red'
            }
        }
    })
}

function isNumeric(num) {
    return !isNaN(num) && (parseInt(num) > 18 || parseInt(num) < 120)
}

function isEmail(mail) {
    if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(mail)) {
        return (true)
    }
    return (false)
}

function isDate(date) {
    return Date.parse(date)
}