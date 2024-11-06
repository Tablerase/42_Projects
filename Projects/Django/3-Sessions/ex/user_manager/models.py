from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager, Group, Permission, PermissionsMixin
from life_pro_tips.models import Vote

class CustomUserManager(BaseUserManager):
    def create_user(self, username, password=None, **extra_fields):
        if not username:
            raise ValueError('The Username field must be set')
        user = self.model(username=username, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user
    
    def create_superuser(self, username, password=None, **extra_fields):
        extra_fields.setdefault('is_staff', True)
        extra_fields.setdefault('is_superuser', True)

        if extra_fields.get('is_staff') is not True:
            raise ValueError('Superuser must have is_staff=True.')
        if extra_fields.get('is_superuser') is not True:
            raise ValueError('Superuser must have is_superuser=True.')

        return self.create_user(username, password, **extra_fields)

class CustomUser(AbstractBaseUser, PermissionsMixin):
    username = models.CharField(max_length=100, unique=True)
    is_staff = models.BooleanField(default=False)
    is_superuser = models.BooleanField(default=False)
    is_active = models.BooleanField(default=True)
    reputation = models.IntegerField(default=0)

    USERNAME_FIELD = 'username'
    REQUIRED_FIELDS = []

    objects = CustomUserManager()
    groups = models.ManyToManyField(Group, related_name='customuser_set', blank=True)
    user_permissions = models.ManyToManyField(Permission, related_name='customuser_set', blank=True)

    def __str__(self):
        return f"{self.username} ({self.reputation}🪙)"

    def update_reputation(self):
        # Calculate the total number of upvotes on tips authored by the user
        total_upvotes = Vote.objects.filter(tip__author=self, vote_type=Vote.UPVOTE).count()
        total_downvotes = Vote.objects.filter(tip__author=self, vote_type=Vote.DOWNVOTE).count()
        self.reputation = (total_upvotes * 5) - (total_downvotes * 2)

        # Add or remove appropriate group according to rep points
        great_voter_group = Group.objects.get(name='GreatVoter')
        great_deleter_group = Group.objects.get(name='GreatDeleter')

        # ?DEBUG: reduce reputation treshold for easier testing
        if self.reputation >= 30:
            self.groups.add(great_deleter_group)
        else:
            self.groups.remove(great_deleter_group)

        if self.reputation >= 15:
            self.groups.add(great_voter_group)
        else:
            self.groups.remove(great_voter_group)

        self.save()

