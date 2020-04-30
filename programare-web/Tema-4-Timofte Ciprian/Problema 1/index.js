$('option').click((e) => {
  selectItem(e.target.id)
});

function selectItem(id) {
  const elementCurent = $('#' + id)

  if ($('#listBaieti').find(currentEl).length != 0) {
    elementCurent.appendTo('#legume')
  }
  else {
    elementCurent.appendTo('#fructe')
  }
}