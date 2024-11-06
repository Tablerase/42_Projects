from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group, Permission

class Command(BaseCommand):
    help = 'Create groups and assign permissions'

    def handle(self, *args, **options):
        group_names = ['GreatVoter', 'GreatDeleter']
        perms = {
            'GreatVoter': Permission.objects.get(codename='downvote_tip'),
            'GreatDeleter': Permission.objects.get(codename='delete_tip'),
        }

        for group in group_names:
            new_group, created = Group.objects.get_or_create(name=group)
            if created:
                group_perm = perms[group]
                new_group.permissions.add(group_perm)
                new_group.save()
                self.stdout.write(self.style.SUCCESS('Successfuly created "%s" group' % group))
            else:
                self.stdout.write(self.style.WARNING('"%s" group already exist' % group))
