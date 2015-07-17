#include "NeroProducer/Core/interface/BareLeptons.hpp"

BareLeptons::BareLeptons(){
    p4 = NULL;
    pdgId = NULL;
    iso = NULL;
    tightId = NULL;
    lepPfPt = NULL;

    //
    chIso=NULL;
    nhIso=NULL;
    phoIso=NULL;
    puIso=NULL;
}

BareLeptons::~BareLeptons(){
}

void BareLeptons::clear(){
    BareP4::clear();

    pdgId -> clear();
    iso -> clear();
    tightId ->clear();
    lepPfPt->clear();    

    chIso->clear();
    nhIso->clear();
    phoIso->clear();
    puIso->clear();
}

void BareLeptons::defineBranches(TTree*t){
    //
    BareP4::defineBranches(t, "lep" );
    //
    pdgId = new vector<int>;
    t->Branch("lepPdgId","vector<int>",&pdgId);
    //
    iso = new vector<float>;
    t->Branch("lepIso","vector<float>",&iso);
    //
    tightId = new vector<int>;
    t->Branch("lepTightId","vector<int>",&tightId);
    //
    lepPfPt = new vector<float>;
    t->Branch("lepPfPt","vector<float>",&lepPfPt);

    // 
    chIso=new vector<float>;
    t->Branch("lepChIso","vector<float>",&chIso);
    nhIso=new vector<float>;
    t->Branch("lepNhIso","vector<float>",&nhIso);
    phoIso=new vector<float>;
    t->Branch("lepPhoIso","vector<float>",&phoIso);
    puIso=new vector<float>;
    t->Branch("lepPuIso","vector<float>",&puIso);
    

}

void BareLeptons::setBranchAddresses(TTree*t){

    BareP4::setBranchAddresses(t,"lep");

    pdgId = new vector<int>;
    t->SetBranchAddress("lepPdgId"	,&pdgId);
    iso = new vector<float>;
    t->SetBranchAddress("lepIso"	,&iso);
    tightId = new vector<int>;
    t->SetBranchAddress("lepTightId"	,&tightId);
    lepPfPt = new vector<float>;
    t->SetBranchAddress("lepPfPt"	,&lepPfPt);

    chIso=new vector<float>;
    t->SetBranchAddress("lepChIso",&chIso);
    nhIso=new vector<float>;
    t->SetBranchAddress("lepNhIso",&nhIso);
    phoIso=new vector<float>;
    t->SetBranchAddress("lepPhoIso",&phoIso);
    puIso=new vector<float>;
    t->SetBranchAddress("lepPuIso",&puIso);

}

// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4