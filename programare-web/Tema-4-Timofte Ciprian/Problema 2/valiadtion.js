$(document).ready(function () {
    function validate() {
        $('input').each((index, input) => {
            if ($(input).prop('name') === 'name') {
                if (/\d/.test($(input).val())) {
                    $(input).css('border', '2px solid green')
                } else {
                    $(input).css('border', '2px solid red')
                }
            } else if ($(input).prop('name') === 'age') {
                if (isNumeric($(input).val())) {
                    $(input).css('border', '2px solid green')
                } else {
                    $(input).css('border', '2px solid red')
                }
            } else if ($(input).prop('name') === 'email') {
                if (isEmail($(input).val())) {
                    $(input).css('border', '2px solid green')
                } else {
                    $(input).css('border', '2px solid red')
                }
            } else if ($(input).prop('name') === 'birthday') {
                if (!isNaN(isDate($(input).val()))) {
                    $(input).css('border', '2px solid green')
                } else {
                    $(input).css('border', '2px solid red')
                }
            }
        })
    }

    $('#buton').click(() => {
        validate()
    });

    function isNumeric(num) {
        return !isNaN(num) && (parseInt(num) > 18 || parseInt(num) < 120)
    }

    function isEmail(mail) {
        if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(mail)) {
            return (true);
        }
        return (false);
    }

    function isDate(date) {
        return Date.parse(date)
    }
});

