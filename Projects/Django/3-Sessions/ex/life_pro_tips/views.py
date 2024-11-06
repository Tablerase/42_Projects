from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required
from .forms import TipForm
from .models import Tip, Vote

def home(request):
    if request.method == 'POST':
        form = TipForm(request.POST)
        if form.is_valid():
            tip = form.save(commit=False)
            tip.author = request.user
            tip.save()
            return redirect('home')
    else:
        form = TipForm()
    tips_list = Tip.objects.all().order_by('-date')
    context = {
        'tips_list': tips_list,
        'form': form,
    }
    return render(request, 'home.html', context)

@login_required(login_url='/user/login')
def upvote_tip(request, tip_id):
    tip = get_object_or_404(Tip, id=tip_id)
    vote, created = Vote.objects.get_or_create(user=request.user, tip=tip)
    if not created and vote.vote_type == Vote.UPVOTE:
        #Delete an existing vote
        vote.delete()
    else:
        #Update or create a vote
        vote.vote_type = Vote.UPVOTE
        vote.save()
    return redirect('home')

@login_required(login_url='/user/login')
def downvote_tip(request, tip_id):
    tip = get_object_or_404(Tip, id=tip_id)
    vote, created = Vote.objects.get_or_create(user=request.user, tip=tip)
    if not created and vote.vote_type == Vote.DOWNVOTE:
        vote.delete()
    else:
        vote.vote_type = Vote.DOWNVOTE
        vote.save()
    return redirect('home')

@login_required(login_url='/user/login')
def delete_tip(request, tip_id):
    tip = get_object_or_404(Tip, id=tip_id)
    if tip.author == request.user or request.user.has_perm('life_pro_tips.delete_tip'):
        tip.delete()
    return redirect('home')
