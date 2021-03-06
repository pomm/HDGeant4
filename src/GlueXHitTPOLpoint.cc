//
// GlueXHitTPOLpoint - class implementation
//
// author: richard.t.jones at uconn.edu
// version: december 16, 2016

#include "GlueXHitTPOLpoint.hh"

G4ThreadLocal G4Allocator<GlueXHitTPOLpoint>* GlueXHitTPOLpointAllocator = 0;

int GlueXHitTPOLpoint::operator==(const GlueXHitTPOLpoint &right) const
{
   if (E_GeV          == right.E_GeV       &&
       dEdx_GeV_cm    == right.dEdx_GeV_cm &&
       primary_       == right.primary_    &&
       ptype_G3       == right.ptype_G3    &&
       px_GeV         == right.px_GeV      &&
       py_GeV         == right.py_GeV      &&
       pz_GeV         == right.pz_GeV      &&
       x_cm           == right.x_cm        &&
       y_cm           == right.y_cm        &&
       z_cm           == right.z_cm        &&
       t_ns           == right.t_ns        &&
       track_         == right.track_      &&
       trackID_       == right.trackID_    )
   {
      return 1;
   }
   return 0;
}

GlueXHitTPOLpoint &GlueXHitTPOLpoint::operator+=(const GlueXHitTPOLpoint &right)
{
   G4cerr << "Error in GlueXHitTPOLpoint::operator+= - "
          << "illegal attempt to merge two TruthPoint objects in the tpol!"
          << G4endl;
   return *this;
}

void GlueXHitTPOLpoint::Draw() const
{
   // not yet implemented
}

void GlueXHitTPOLpoint::Print() const
{
   G4cout << "GlueXHitTPOLpoint:" << G4endl
          << "   track = " << track_ << G4endl
          << "   trackID = " << trackID_ << G4endl
          << "   E = " << E_GeV << " GeV" << G4endl
          << "   dEdx = " << dEdx_GeV_cm << " GeV/cm" << G4endl
          << "   primary = " << primary_ << G4endl
          << "   ptype = " << ptype_G3 << G4endl
          << "   px = " << px_GeV << " GeV/c" << G4endl
          << "   py = " << py_GeV << " GeV/c" << G4endl
          << "   pz = " << pz_GeV << " GeV/c" << G4endl
          << "   x = " << x_cm << " cm" << G4endl
          << "   y = " << y_cm << " cm" << G4endl
          << "   z = " << z_cm << " cm" << G4endl
          << "   t = " << t_ns << " ns" << G4endl
          << G4endl;
}

void printallhits(GlueXHitsMapTPOLpoint *hitsmap)
{
   std::map<int, GlueXHitTPOLpoint*> *map = hitsmap->GetMap();
   std::map<int, GlueXHitTPOLpoint*>::const_iterator iter;
   G4cout << "G4THitsMap " << hitsmap->GetName() << " with " << hitsmap->entries()
          << " entries:" << G4endl;
   for (iter = map->begin(); iter != map->end(); ++iter) {
      G4cout << "  key=" << iter->first << " ";
      iter->second->Print();
   }
}
