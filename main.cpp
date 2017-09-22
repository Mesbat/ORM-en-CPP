// PROJECT OwlORM, Etna 2017, Mesbat_y & Abbass_S //
// ---------------------------------------------- //

#include "headers/headers.hh"

class Utilisateur : public ORM::Table {
public:
	ORM::Field userID;
	ORM::Field username;

	Utilisateur() : ORM::Table("utilisateurs", "user_id") {
		addField("user_id", userID);
		addField("username", username);
	}
};

int main(void) {
	ORM::DB db;
  db.connect("localhost", "root", "");

  std::vector<Utilisateur> users = db.selectAll<Utilisateur>();
  	for (Utilisateur& user : users) {
  		std::cout << "Utilisateur #" << user.userID << ": " << user.username.getValue() << "\n";
  		//user.OrmDelete(); #PAS DE FONCTION DELETE
  	}

  Utilisateur newUser;
  newUser.username = "Nouvel utilisateur";
  db.save(newUser);
  std::cout << "Nouvel utilisateur: #" << newUser.userID << "\n";
	newUser.username = "Utilisateur changé";
  db.save(newUser);

  Utilisateur firstUser = db.findById<Utilisateur>(1);
  std::cout << "Nom du premier utilisateur : " << firstUser.username.getValue() << "\n";

  return 0;
}
