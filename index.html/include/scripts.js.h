document.addEventListener("DOMContentLoaded", () => {
    const animalInfoContainer = document.getElementById("animal-info");
    const animalId = "123"; // 动物的ID

    fetch(`/api/animals/${animalId}`)
        .then(response => response.json())
        .then(animal => {
            const animalInfoHTML = `
                <h2>${animal.name}</h2>
                <p><strong>分类：</strong>${animal.category}</p>
                <p><strong>描述：</strong>${animal.description}</p>
                <img src="/images/${animal.image}" alt="${animal.name}">
            `;
            animalInfoContainer.innerHTML = animalInfoHTML;
        })
        .catch(error => {
            console.error('Error fetching animal information:', error);
        });
});
