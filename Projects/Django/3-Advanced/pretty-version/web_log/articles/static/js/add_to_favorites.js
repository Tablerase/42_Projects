// Fetch AddFavoriteView Form  
document.addEventListener('DOMContentLoaded', function() {
  // Recover form
  const form = document.getElementById('favorite-form');
  // Listen to submit button
  if (form){
  form.addEventListener('submit', function(event) {
    // prevent default reload when submit
    event.preventDefault();
    // Create Form data and CSRF
    const formData = new FormData(form);
    const csrfToken = formData.get('csrfmiddlewaretoken');
    // API Call
    fetch(form.action, {
      method: 'POST',
      headers: {
        'X-CSRFToken': csrfToken,
      },
      body: formData,
    }) // Response Handling
    .then(response => response.json())
    .then(data => {
      if (data.success === 'Add') {
        alert('Article added to favorites!');
      } else if (data.success === 'Already'){
        alert('Article already in favorties!')
      } else {
        alert('Failed to add article to favorites.');
        console.error('Error:', data.errors);
      }
    })
    .catch(error => {
      console.error('Error:', error);
      alert('An error occurred.');
    });

    });
  };
});
