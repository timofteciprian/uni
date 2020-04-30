function selectItem(id) {
  const legume = document.getElementById('legume')
  const fructe = document.getElementById('fructe')
  const elementCurent = document.getElementById(id)

  if (legume.contains(elementCurent)) {
    fructe.appendChild(elementCurent)
  }
  else {
    legume.appendChild(elementCurent)
  }
}

