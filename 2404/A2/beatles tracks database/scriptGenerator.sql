select '//add recordings';
select '//add -r album_id title producer year';
select 'add -r ' || id || ' "' || title || '" "' ||
                 artist ||'" "' || producer || '" ' || 
				 year from recordings;
				 
select '//add songs';
select '//add -s sid title composer';
select 'add -s ' || sid || ' "' || title || '" "' ||
                 composer ||'"' from songs;
				 
select '//add tracks';
select '//add -t track_id albumID songID track_number';
select 'add -t '|| tid || ' ' || albumID || ' ' || songID || ' ' || track_number from tracks;
                
select '//add users';
select '//add -u user_id name';
select 'add -u ' || user_id || ' "' || name || '"' from users;

select '//add playlists';
select '//add -p user_id playlist_name';
select 'add -p ' || user_id || ' "' || playlist_name || '"' from playlists;

select '//add playlist tracks';
select '//add -l userid playlist_name, track_id';
select 'add -l ' || user_id || ' "' || playlist_name || '" ' || track_id from playlist_tracks;
